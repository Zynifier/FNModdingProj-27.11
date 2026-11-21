// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "FortClientOnlyActor.h"
#include "STW/AI/GameDifficulty/FortGameDifficultyCalculationData.h"
#include "UI/FrontEnd/FortHexMapTypes.h"
#include "UI/FrontEnd/FortTheaterInfo.h"
#include "UI/FrontEnd/FortTheaterMapViewer.h"
#include "FortTheaterMapTile.generated.h"

class AActor;
class UFortQuestItem;
class UFortZoneTheme;
class UMaterialInstanceDynamic;
class UStaticMeshComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Navigation"))
class AFortTheaterMapTile : public AFortClientOnlyActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Tile")
	bool DoesTileAllowQuickplay() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	FName GetMissionAlertCategoryName() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	FGameplayTagContainer GetMissionAlertVisualTags() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	int32 GetMissionContentDifficultyLevel() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool GetMissionDefinitionIcon(FSlateBrush& OutMissionDefIcon) const;

	UFUNCTION(BlueprintPure, Category="Tile")
	FGameDifficultyInfo GetZoneDifficulty() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool HasValidMissionData() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool IsMissionAlertTile() const;

	UFUNCTION(BlueprintPure)
	bool IsTeamRatingDataValid() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool IsTileHidden() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool IsTileInPhoenixTheater() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool IsTileLocked() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool IsTilePlayable() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool IsTileQuestRecommended() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool IsTileSelectable() const;

	UFUNCTION(BlueprintPure, Category="Tile")
	bool IsTileValidForMarkedQuest(UFortQuestItem*& OutMarkedQuest) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnClientDeselect();

	UFUNCTION(BlueprintImplementableEvent)
	void OnClientSelect();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDefocus();

	UFUNCTION()
	virtual void OnDeselectWrapper(bool bIsGameSessionOwner);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisableGoToPrompt();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnableGoToPrompt();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnFocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHostDeselect();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHostSelect();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializeTile();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMarkedQuestChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMissionDataUpdated();

	UFUNCTION()
	void OnMouseOverBegin(AActor* MousedOverActor);

	UFUNCTION()
	void OnMouseOverEnd(AActor* MousedOverActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnProfileBannerChanged();

	UFUNCTION()
	virtual void OnSelectWrapper(bool bIsGameSessionOwner);

	UFUNCTION()
	void OnTileClicked(AActor* ClickedActor, FKey ButtonReleased);

	UFUNCTION(BlueprintImplementableEvent)
	void RefreshTile();

	UPROPERTY(BlueprintReadOnly, Category="Tile")
	bool bFocused;

	UPROPERTY(BlueprintReadOnly, Category="Tile")
	bool bHostSelected;

	UPROPERTY(BlueprintReadOnly, Category="Tile")
	bool bGoToPromptEnabled;

	UPROPERTY()
	FFortHexMapCoord MapCoord;

	UPROPERTY()
	bool bHasFinishedLoading;

protected:
	UPROPERTY(BlueprintReadOnly, Category="TheaterMapTile")
	EFortTheaterMapTileType TileType;

	UPROPERTY()
	TSubclassOf<UFortZoneTheme> ZoneThemeClass;

	UPROPERTY()
	int32 TileIndex;

	UPROPERTY()
	int32 RegionIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	FVector SelectionOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	FVector FocusOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	float SelectionInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	float NormalBrightness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	float LockedBrightness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	float FocusedBrightness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	float SelectedBrightnessRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	float SelectedPulseSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Selection")
	bool bEnableBrightnessCode;

	UPROPERTY(BlueprintReadOnly, Category="TheaterMapTile")
	bool bDisallowQuickplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Display")
	float StaticMeshMaterialID;

	UPROPERTY()
	FVector InitialLocation;

	UPROPERTY()
	FFortAvailableMissionData MissionData;

	UPROPERTY()
	FFortAvailableMissionData LastValidMissionData;

	UPROPERTY()
	FDataTableRowHandle ZoneDifficultyInfo;

	UPROPERTY()
	FFortAvailableMissionAlertData MissionAlertData;

	UPROPERTY(BlueprintReadWrite, Category="Display")
	TArray<TObjectPtr<UMaterialInstanceDynamic>> AdjacencyMIDs;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Display", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

};

