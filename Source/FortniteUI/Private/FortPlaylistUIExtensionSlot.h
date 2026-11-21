// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/DynamicEntryBox.h"
#include "FortUIExtensionSlot.h"
#include "FortPlaylistUIExtensionSlot.generated.h"

class UFortPlaylistUIExtensionLoader;

UCLASS()
class UFortPlaylistUIExtensionSlot : public UDynamicEntryBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPlaylistUIExtensionSlot")
	TArray<EUIExtensionSlot> ExtensionSlots;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortPlaylistUIExtensionLoader> PlaylistUIExtensionLoader;

};

