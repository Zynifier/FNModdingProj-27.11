// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaDiscoverabilityBase.h"
#include "AthenaDiscoveredAreaOverlay.generated.h"

class USoundCue;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS()
class UAthenaDiscoveredAreaOverlay : public UAthenaDiscoverabilityBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Playlist Extension Widget Created"))
	void BP_HandlePlaylistExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewDiscovery(const FText& LocalizedLocationName, const TSoftObjectPtr<USoundCue>& DiscoveredSoundCue, bool bIsNamedLocation, bool bIsDiscovered);

};

