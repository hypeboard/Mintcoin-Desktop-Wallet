#ifndef ASKPASSPHRASEDIALOG_H
#define ASKPASSPHRASEDIALOG_H

#include <QDialog>

namespace Ui {
    class AskPassphraseDialog;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskPassphraseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,    /**< Ask passphrase twice and encrypt */
        UnlockMinting, /**< Ask passphrase and unlock for minting only */
        Unlock,     /**< Ask passphrase and unlock */
        ChangePass, /**< Ask old passphrase + new passphrase twice */
        Decrypt,     /**< Ask passphrase and decrypt wallet */
        PassToSend   /**< Ask passphrase and send transaction */
    };

    explicit AskPassphraseDialog(Mode mode, QWidget *parent = 0);
    ~AskPassphraseDialog();

    void accept();

    void setModel(WalletModel *model);

private:
    Ui::AskPassphraseDialog *ui;
    Mode mode;
    WalletModel *model;
    bool fCapsLock;

private slots:
    void textChanged();
    bool event(QEvent *event);
    bool eventFilter(QObject *, QEvent *event);
};

#endif // ASKPASSPHRASEDIALOG_H
