// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortLobby.generated.h"

class AAthenaSquadPedestalGroup;
class AFortTeamMemberPedestal;
class UFortLobbyPlayerPanel;
class UFortRadialPicker;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class FORTNITEUI_API UFortLobbyWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsAnyFauxModelOpen() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnPlayerClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerPanelHidden();

protected:
	UFUNCTION()
	void DynamicHandleLoadingScreenVisibilityChanged(bool IsVisible);

	UFUNCTION()
	virtual void HandleEmoteClicked(bool& bPassThrough);

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortTeamMemberPedestal>> VisualOrderedPedestals;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLobbyWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortLobbyPlayerPanel> PlayerPanel_PlayerOptions;

	UPROPERTY(EditAnywhere, Category="FortLobbyWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle EmoteInputAction;

private:
	UPROPERTY(Transient)
	TObjectPtr<AAthenaSquadPedestalGroup> SquadPedestalGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLobbyWidget", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortRadialPicker> Radial_EmotePicker;

};

