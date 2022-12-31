# hen 3.2.3 rus mod

![image](https://i.ibb.co/0QZBxWk/screenshot-2022-11-27-04-58-38.png)
![image](https://i1.imageban.ru/out/2022/12/04/bacc176f87f8897e1ad81ff4be2a3f67.jpg)

## Изменения в 3.2.3
- Добавлено опция включения горячих клавиш (L2 и R2). Для большей совместимости горячие клавиши по умолчанию выключены. 
Если у Вас горячие клавиши не дают активировать HEN, через файловый обозреватель в разделе сеть удалите (unlink) файл dev_hdd0\hen\hotkeys.off

## Изменения в 3.2.2
- Добавлена очистка логов, которые отправляются при соединении в PSN с целью уменьшения риска бана.
- Добавлено отображение того, чиститься ли кеш браузера, история, аутентификация. Добавлена опция включения/отключения логов очистки.
- Включена обработка клавиш:
    - R2 отключает dev_hdd\boot*.txt из загрузки (бывает необходимо при конфликте с плагинами)
    - L2 отключает все плагины в том числе и плагины hen, поэтому информацию о включении хен видно не будет, иконка не сменится, но ядро загрузится, в чем можно убедиться запустив игру/софт, либо обновив XMB (например через вход в дистанционное управление и выход - тогда иконка изменится)

## Изменения в 3.2.1
- Удалено обработка горячих клавиш (для большей совместимости с некоторыми моделями)

## Изменения в 3.2.0
### Плагин:
- Добавлено: Автоматическая перезагрузка после успешной первоначальной установки HEN из сети и USB (метод 2.2)
- Добавлено: доступ в черный список к доморощенным NP0APOLLO / NP00PKGI3, когда системные вызовы CFW отключены
- Добавлено: поддержка Libcrypt для игр PS1 (файлы LSF/SBI).
- Добавлено: PSX Bios исправлен с кодом продукта 0x85 для игр PAL.
- Добавлено: опции переключения на очистку веб-браузера при активации HEN. (Аутентификация, кэш, файлы cookie, история)

### Полезная нагрузка:
- Добавлено: обнаружение горячих клавиш:
    - удерживайте R2, чтобы отключить boot_plugins.txt (бывает полезно, когда плагины вешают пс3)
- Добавлено: улучшен статус open_path.
- Улучшено: Map_path.
- Улучшено: PS3MAPI.

## Изменения в 3.1.7
- Добавлены функции Mamba 8.4 (Изменен ps3mapi_process_page_allocate, чтобы использовать page_table в качестве процесса ввода и вывода, а также сопоставление page_address ядра, которое было выделено. Добавлен ps3mapi_process_page_free, который принимает page_table (сопоставление page_address процесса/ядра) и освобождает его.
- Заменен rco для возможности обновления с hdd в пункте обновление системы. Для отображения включать нужно где настройки сети (после комбинации будет ниже). Комбинация клавиш: L1+L2+R1+R2+L3+dpad_down должно появится меню, там пункт system update debug. обновления нужно размещать в dev_hdd0\updater\01\ (вы можете назвать файл обновления как угодно). Достаточно включить 1 раз и потом после активации HEN дополнительные пункты будут доступны.
- Убрал предупреждение об эпилепсии (пусто)

## Изменения в 3.1.6
- Перекомпилировал с целью устранения проблем с папочными играми (если проблемы остаются, смените бекап менеджер)
- Мелкие правки в меню

## Изменения в 3.1.5
- Добавлено отображение различных магазинов через обслуживание (по умолчанию отключено)
- :exclamation: **ВНИМАНИЕ**:exclamation: Совместимость магазинов с HEN RUS не гарантируется! Магазины могут поломать меню, добавить свой метод инициализации, так что будьте аккуратнее :exclamation:
- аудио патч по умолчанию теперь выключен
- добавлена функция удаления HEN через обслуживание
- мелкие правки

## Изменения в 3.1.4
- Добавлено отображение сейвов ps2 в утилах
- обновлена информация о системе (3.1.4)

## Изменения в 3.1.3
- Изменены иконки HEN ON / HEN OFF для более четкого понимания включен хен или нет (Иконки изготовила @Виктория)
- Изменен метод восстановления бекапа act.bak
- Добавлена очистка (удаляются webbrowser/history.xml, http/auth_cache.dat, http/cookie.dat);
- расширение RAP теперь может быть как rap, так и RAP
- исправлено отображение 1080p (ранее было описание как 2160)
- мелкие правки

## Изменения в 3.1.2
### Добавлены опции в раздел обслуживания:
- Теперь можно включить/отключить автообновление через интернет и с флешки (dev_usb00?/HEN_UPD.pkg) (если опция выключена - хен срабатывает чуть быстрее)
- Теперь можно включить/отключить патч libaudio для наушников, поскольку с наушниками Sony конфликты - выбирайте нужно ли это вам или нет
- Теперь можно включить/скрыть пункт "включить hen" (работает после обновления xmb - если включен, будет виден пункт и надпись "хен уже активирован", если выключен, пункт будет скрыт)
- Теперь можно включить/скрыть утилиты
- Теперь можно включить/скрыть пункт "Управление файлами PKG"

### Другое:
- Заменен сервер проверки обновлений
- Иконки к указанным опциям переключаются
- Теперь можно сделать обновление с помощью файла HEN_UPD.pkg не только с правого порта (dev_usb000), но и с левого (dev_usb001)
- Добавлен перевод для новых опций
- xai_plugin доработан.
- Обновлена информация о PS3HEN
- Другие мелкие правки

