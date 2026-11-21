// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortShowdownTournamentTile.generated.h"

class UFortShowdownDetailView;
class UFortTournamentPosterViolator;
class UTournamentListEntryData;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortShowdownTournamentTile : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FString GetTileTournament();

	UFUNCTION(BlueprintPure)
	UTournamentListEntryData* GetTournamentListEntryData() const;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownTournamentTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTournamentPosterViolator> ShowdownDetailView_Violator;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownTournamentTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortShowdownDetailView> ShowdownDetailView_Poster;

	UPROPERTY()
	TObjectPtr<UTournamentListEntryData> TournamentListEntryData;

};

