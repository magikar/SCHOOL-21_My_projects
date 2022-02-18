<?php
/**
 * Основные параметры WordPress.
 *
 * Скрипт для создания wp-config.php использует этот файл в процессе
 * установки. Необязательно использовать веб-интерфейс, можно
 * скопировать файл в "wp-config.php" и заполнить значения вручную.
 *
 * Этот файл содержит следующие параметры:
 *
 * * Настройки MySQL
 * * Секретные ключи
 * * Префикс таблиц базы данных
 * * ABSPATH
 *
 * @link https://ru.wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Параметры MySQL: Эту информацию можно получить у вашего хостинг-провайдера ** //
/** Имя базы данных для WordPress */
define( 'DB_NAME', 'db_tmagikar_wp' );

/** Имя пользователя MySQL */
define( 'DB_USER', 'tmagikar' );

/** Пароль к базе данных MySQL */
define( 'DB_PASSWORD', 'tmagikar' );

/** Имя сервера MySQL */
define( 'DB_HOST', 'localhost' );

/** Кодировка базы данных для создания таблиц. */
define( 'DB_CHARSET', 'utf8' );

/** Схема сопоставления. Не меняйте, если не уверены. */
define( 'DB_COLLATE', '' );

/**#@+
 * Уникальные ключи и соли для аутентификации.
 *
 * Смените значение каждой константы на уникальную фразу.
 * Можно сгенерировать их с помощью {@link https://api.wordpress.org/secret-key/1.1/salt/ сервиса ключей на WordPress.org}
 * Можно изменить их, чтобы сделать существующие файлы cookies недействительными. Пользователям потребуется авторизоваться снова.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '3[QO[>Z>mh.@;N~.r|%8c>H+N>XV{!)J==|.H=1dNP8:Cq)^jN kWP=B(8csZo+@');
define('SECURE_AUTH_KEY',  'L-Z;WB$WD9,*1<k*TB>OfpY,c!>/.d)U -7ks[-VviZsmW{n .5:Yd{b+aYE2f2=');
define('LOGGED_IN_KEY',    ']=2x .@367@&gU>|QDv*YXO?-:C2e$.~l!QN >1JkRM_R+~IFNRfMu>&+!!qL{{=');
define('NONCE_KEY',        'J:,.pTM[9`X-~sLoplUzMnw|orPW+)9eio<k>K_?4_lk!*.bH0d2JA!](O1(0]dj');
define('AUTH_SALT',        ']r|yMt@-{7fx]F3-8f8F &T+WF1~=`qft_ktqf+iDyKTGF)aU%S=!4k%1Qr&6_L`');
define('SECURE_AUTH_SALT', 'rny2MzqVd2#K/Q!Jm-Ts+AH;oYRr9x0$UAM2o*MCNL:iEvd.:T?8_AE`@Z` hsfM');
define('LOGGED_IN_SALT',   'fm-j|Y9qVZr5<sQ|!dt:fZ;TiT~h7MUXnnLL<qNuQg~8QT1g|M^j@9V+&Pk4M`Hr');
define('NONCE_SALT',       ')+$JnU9Mq2i_diCV3mO*SW?^_i{rp#9|_O)2z#DmmX-ZG%kq[V<~0[Y$8PYdM$4l');

/**#@-*/

/**
 * Префикс таблиц в базе данных WordPress.
 *
 * Можно установить несколько сайтов в одну базу данных, если использовать
 * разные префиксы. Пожалуйста, указывайте только цифры, буквы и знак подчеркивания.
 */
$table_prefix = 'wp_';

/**
 * Для разработчиков: Режим отладки WordPress.
 *
 * Измените это значение на true, чтобы включить отображение уведомлений при разработке.
 * Разработчикам плагинов и тем настоятельно рекомендуется использовать WP_DEBUG
 * в своём рабочем окружении.
 *
 * Информацию о других отладочных константах можно найти в документации.
 *
 * @link https://ru.wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Это всё, дальше не редактируем. Успехов! */

/** Абсолютный путь к директории WordPress. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Инициализирует переменные WordPress и подключает файлы. */
require_once ABSPATH . 'wp-settings.php';
