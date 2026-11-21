// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NPCStatusWidgetBase.generated.h"

class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UNPCStatusWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UNPCStatusWidgetBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Playlist Extension Widget Created"))
	void BP_HandlePlaylistExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

};

