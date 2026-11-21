// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "Online/FortTournamentStatInfo.h"
#include "FortHUDScoringAlert.generated.h"

class AFortMinigame;
class AFortPlayerStateAthena;
class UCommonLazyImage;
class UCommonTextBlock;
class UFortHUDPointCounter;
class UFortTournamentAbandonMatchDialog;
enum class EMatchAbandonState : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortHUDScoringAlert : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandlePointAnimationFinished();

	UFUNCTION()
	void OnPlayerMatchAbandonStateChanged(EMatchAbandonState OldState, EMatchAbandonState NewState);

	UFUNCTION()
	void OnPlayerPlacementChanged(AFortPlayerStateAthena* Sender, int32 NewPlayerPlacement);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPointScored();

	UFUNCTION()
	void OnTeamPlacementChanged(int32 NewTeamPlacement);

	UFUNCTION()
	void OnTournamentStatUpdate(const FFortTournamentStatInfo& TournamentStatInfo);

	UPROPERTY(EditAnywhere, Category="FortHUDScoringAlert")
	FText PointGainFormat;

private:
	UFUNCTION()
	void OnMinigameCurrentRoundChanged(AFortMinigame* Minigame, int32 CurrentRound);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHUDScoringAlert", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortHUDPointCounter> HUDPointCounter;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ScoreDesc;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PointCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Icon_Scoring;

	UPROPERTY(EditAnywhere, Category="FortHUDScoringAlert")
	TSubclassOf<UFortTournamentAbandonMatchDialog> AbandonMatchClass;

};

