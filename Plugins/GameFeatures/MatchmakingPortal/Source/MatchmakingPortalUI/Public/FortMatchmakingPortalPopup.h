// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Core/FortInitializeFromObjectInterface.h"
#include "Creative/Components/HeaderDescriptionHUDComponent.h"
#include "FortPortalHUDDetails.h"
#include "FortMatchmakingPortalPopup.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerControllerZone;
class UCommonActivatableWidget;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortActivityDetailsModal;
class UFortAthenaCreativeMatchmakingWidget;
class UFortGameActivity;
class UFortKeybindWidget;
class UHeaderDescriptionHUDComponent;

UCLASS()
class UFortMatchmakingPortalPopup : public UFortPortalHUDDetails, public IFortInitializeFromObjectInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleHUDShow(const bool bShow, const bool bShouldAnimate);

	UFUNCTION()
	void HandleLoadScreenChanged(AFortPlayerControllerAthena* PlayerController, bool bLoadScreenEnabled, FText HUDReason);

	UFUNCTION()
	void HandleStartedRespawn(AFortPlayerControllerZone* PlayerController);

	UFUNCTION()
	void HandleWidgetUpdate();

	UFUNCTION(BlueprintPure)
	bool HasActivityToShow() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerCanInteractChanged(const bool bPlayerCanInteract, const FText& Message);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowPortalPopup(const bool bShow, const bool bAnimate);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVisuals(const UHeaderDescriptionHUDComponent* HUDComponent);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivityDetailsModal> MatchmakingPortalModalWidget;

	UPROPERTY(BlueprintReadOnly, Category="FortMatchmakingPortalPopup")
	FVector WorldPointerLocation;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingPortalPopup")
	FText CreatorNameTextFormat;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingPortalPopup")
	TWeakObjectPtr<UHeaderDescriptionHUDComponent> CachedHUDComponent;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingPortalPopup")
	TSubclassOf<UFortActivityDetailsModal> IslandModal;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BindOverlapEvents();

	UFUNCTION(BlueprintImplementableEvent)
	bool GetIslandData(FMatchmakingPortalPopupData& OutIslandData, UHeaderDescriptionHUDComponent* HUDComponent);

	UFUNCTION(BlueprintImplementableEvent)
	UFortAthenaCreativeMatchmakingWidget* GetMatchmakingFeedbackWidget(const UCommonActivatableWidget* MatchmakingFeedbackContainer) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HandleOnPortalDetailsVisibilityCheck(bool bShowWidget);

	UFUNCTION(BlueprintImplementableEvent)
	bool IsInteractingDeviceAMatchmakingPortal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLockStateChanged();

	UPROPERTY(BlueprintReadWrite, Category="FortMatchmakingPortalPopup")
	FMatchmakingPortalPopupData CachedIslandData;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingPortalPopup")
	FText InvalidLinkCodeWarningText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMatchmakingPortalPopup", meta=(ClampMin="0.100000"))
	float MatchmakingFeedbackDelayTime;

	UPROPERTY(BlueprintReadWrite, Category="FortMatchmakingPortalPopup")
	uint8 bIsWithinPortalRange : 1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingPortalPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_CreatorName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IslandName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingPortalPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ActivityTags;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingPortalPopup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> GlobalActionKeybindWidget;

	UPROPERTY(BlueprintReadOnly, Category="FortMatchmakingPortalPopup")
	TObjectPtr<UFortGameActivity> CachedGameActivity;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMatchmakingPortalPopup", meta=(AllowPrivateAccess="TRUE"))
	FText InteractionMessage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMatchmakingPortalPopup", meta=(AllowPrivateAccess="TRUE"))
	FText InteractionMessage_Disabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMatchmakingPortalPopup", meta=(AllowPrivateAccess="TRUE"))
	FText InteractionMessage_PartyLeadOnly;

};

