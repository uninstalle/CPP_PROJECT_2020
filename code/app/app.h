#include "../view/view.h"
#include "../viewmodel/viewmodel.h"
#include "../model/model.h"

#ifndef APP_H
#define APP_H

#endif // APP_H

class App
{
private:
    using EventFunction = std::function<void()>;
    using CallbackFunction = std::function<void()>;
    using WorkFunction = std::function<void()>;
    template<typename T>
    using ptr = std::shared_ptr<T>;
private:
    ptr<View> view;
    ptr<ViewModel> viewModel;
    ptr<Model> model;
public:
    App()
    {
        view = std::make_shared<View>();
        viewModel = std::make_shared<ViewModel>();
        model = std::make_shared<Model>();
        model->setLatexString("");
        viewModel->bindModel(model);

        view->setRenderLatexString(viewModel->getRenderLatexString());
        view->setDisplayLatexFormula(viewModel->getGetFormulaResult());
        view->setLoadImg4Dir(viewModel->getLoadImg4Dir());
        view->setChangeLatexFormula(viewModel->getChangeLatexFormula());
        view->setDisplayHelpDocument(viewModel->getDisplayHelpDocument());

        view->setImgLabel(std::make_shared<QLabel>());
        view->setLatexLabel(std::make_shared<QLabel>());
        view->setLatexEditor(std::make_shared<QPlainTextEdit>());
        view->setTimer(std::make_shared<QTimer>());

        // 绑定数据
        view->setLatexFormula(viewModel->getLatexString());
        // 绑定通知
        view->setLatexStringViewUpdateNotifier(viewModel->getLatexStringViewUpdateNotifier());
        viewModel->setLatexStringViewUpdateNotifier(view->getLatexStringViewUpdateNotifier());
    };
    void run()
    {
        view->initQLayout();
        view->show();
    }
};
