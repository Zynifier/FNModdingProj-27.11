// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortShowdownScreen.generated.h"

class UCommonButtonBase;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortFlagImage;
class UFortFlagSelectionModal;
class UFortPersistentLeaderboardScreen;
class UFortShowdownRegionButton;
class UFortShowdownTournamentListView;
class UFortShowdownTournamentTile;
class UFortTournamentModal;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortShowdownScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="FortShowdownScreen")
	void NavigateTournamentLeft();

	UFUNCTION(BlueprintCallable, Category="FortShowdownScreen")
	void NavigateTournamentRight();

	UFUNCTION(BlueprintImplementableEvent)
	void SelectedEndTournament(bool bEndIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void SelectedFrontTournament(bool bFrontIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void SelectedTournamentChanged(const FString& SelectedTournament);

	UPROPERTY(EditInstanceOnly, Category="FortShowdownScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle HypeLeaderboardActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortShowdownScreen")
	TSubclassOf<UFortPersistentLeaderboardScreen> HypeLeaderboardScreenClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="FortShowdownScreen", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortShowdownTournamentTile> TileItemClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="FortShowdownScreen")
	TSubclassOf<UFortTournamentModal> TournamentModalClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Details;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_RegionText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortShowdownTournamentListView> ListView_TournamentList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortShowdownRegionButton> Button_RegionSelection;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LoadingSpinner;

	UPROPERTY(BlueprintReadWrite, Category="FortShowdownScreen")
	bool bIsUsingGamePad;

private:
	UFUNCTION()
	void HandlePopupStateChanged(bool bIsOpen);

	UFUNCTION()
	void HandleSelectedTileChanged(UCommonButtonLegacy* Button, int32 ButtonIndex);

	UPROPERTY(EditAnywhere, Category="FortShowdownScreen")
	TSubclassOf<UFortFlagSelectionModal> FortFlagSelectionModalClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownScreen", meta=(AllowPrivateAccess="true", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ChangeFlag;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownScreen", meta=(AllowPrivateAccess="true", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortFlagImage> Image_YourFlag;

};

