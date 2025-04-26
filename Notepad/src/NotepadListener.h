/*
 * Leet.UI.DuiKit.NotePad
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the Simple Classic Theme License as published by Anis
 * Errais (Leet), either version 1.0 of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the Simple Classic Theme License along
 * with this program. If not, see <https://simpleclassictheme.nl/license.html>.
 *
 * NotepadListener.h: Listener implemented for NotepadWindow
 *
 */

#pragma once
#include "stdafx.h"
#include "NotepadWindow.h"

using namespace DirectUI;

namespace DirectUI
{
    struct ThumbDragEvent : public Event
    {
        SIZE sizeDelta;
    };
}

namespace Leet {
namespace UI {
namespace DuiKit {
namespace Notepad
{
    class NotepadListener : public IElementListener
    {
    private:
        NotepadWindow* _pWindow;

    public:
        NotepadListener(NotepadWindow* window) 
        {
            _pWindow = window;
            _pWindow->AddListener(this);
        }

        void OnListenerAttach(Element* peFrom) override { }
        void OnListenerDetach(Element* peFrom) override { }
        bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override { return true;}
        void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override { }

        void OnListenedInput(Element* peFrom, InputEvent* pInput) override
        {
            _pWindow->OnInput(peFrom, pInput);
        }
        void OnListenedEvent(Element* peFrom, Event* pEvent) override
        {
            _pWindow->OnEvent(peFrom, pEvent);
        }
    };

}}}}