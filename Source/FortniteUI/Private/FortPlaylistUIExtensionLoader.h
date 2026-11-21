// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPlaylistUIExtensionLoader.generated.h"

class UObject;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS()
class UFortPlaylistUIExtensionLoader : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleClearPlaylistExtensionWidgetNotSupported();

	UFUNCTION()
	void HandlePlaylistExtensionWidgetCreatedNotSupported(EUIExtensionSlot ExtensionSlot, UUserWidget* Widget);

	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<TObjectPtr<UObject>, TObjectPtr<UUserWidget>> ObjectBoundWidgets;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UUserWidget>> OrphanWidgets;

};

