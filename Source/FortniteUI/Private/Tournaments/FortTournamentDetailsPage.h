// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortTournamentManagerTypes.h"
#include "Showdown/FortShowdownDetailView.h"
#include "FortTournamentDetailsPage.generated.h"

UCLASS(Abstract)
class UFortTournamentDetailsPage : public UFortShowdownDetailView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortShowdownDetailView")
	TArray<FFortShowdownScoringRuleInfo> FindTournamentScoringRules(const FString& TournamentSeriesId, const FString& TournamentId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnActivateScreen();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnHandleBack(bool& bResult);

protected:
	UFUNCTION(BlueprintCallable)
	void HandleBackClicked();

};

