// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortResearchStatTileWidget.generated.h"

class UFortStatItemDefinition;
enum class EFortStatType : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortResearchStatTileWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortResearchStatTileWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	int32 GetCostToIncreaseStat() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	int32 GetCurrentCombinedStatValue() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	int32 GetCurrentPersonalStatValue() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	int32 GetCurrentResearchLevel() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	int32 GetCurrentTeamStatValue() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	int32 GetNextCombinedStatValueDelta() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	int32 GetNextPersonalStatValueDelta() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	int32 GetNextTeamStatValueDelta() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	EFortStatType GetPersonalStatType() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	const FString GetStatIdName() const;

	UFUNCTION(BlueprintPure, Category="ResearchStatTile")
	bool IsAtMaxResearchLevel() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="ResearchStatTile")
	void OnStatChanged();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="ResearchStatTile")
	TObjectPtr<UFortStatItemDefinition> PersonalStatItemDefinition;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="ResearchStatTile")
	TObjectPtr<UFortStatItemDefinition> TeamStatItemDefinition;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="ResearchStatTile")
	FName StatCostCurveName;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="ResearchStatTile")
	FName StatPersonalDeltaCurveName;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="ResearchStatTile")
	FName StatPersonalCumulativeCurveName;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="ResearchStatTile")
	FName StatTeamDeltaCurveName;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="ResearchStatTile")
	FName StatTeamCumulativeCurveName;

};

