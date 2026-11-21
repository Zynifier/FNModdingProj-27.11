// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortActivityLobbyTile.generated.h"

class UCommonTextBlock;
class UFortActivityBrowserTag;
class UFortActivityModeSetSelectionModalBase;
class UFortGameActivity;
class UFortGameActivityProvider;
class UTexture;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityLobbyTile : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FText GetChildActivityDisplayName() const;

	UFUNCTION(BlueprintPure)
	bool IsActivityEpicCreated() const;

	UFUNCTION(BlueprintPure)
	bool IsModeSetActivity() const;

	UFUNCTION(BlueprintCallable)
	void ShowModeSetSelectionModal();

	UFUNCTION(BlueprintCallable)
	void TrySendFirstTimeNotification();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDetailsUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHideChildActivityFirstTimeNotification();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowChildActivityChangedNotification(const FText& DisplayName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowChildActivityFirstTimeNotification();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityLobbyTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityLobbyTile", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortActivityBrowserTag> ActivityBrowserTag_EpicOriginal;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityLobbyTile")
	TSubclassOf<UFortActivityModeSetSelectionModalBase> ActivityModeSetSelectionModalClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivityProvider> ActivityProvider;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortGameActivity>> CachedQueriedActivities;

};

