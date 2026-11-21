// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseFortniteActorWrapper.h"
#include "VerseFortniteCharacter.generated.h"

class AFortPlayerPawnAthena;
class APawn;

UCLASS()
class VERSEFORTNITE_API UVerseFortniteCharacter : public UVerseFortniteActorWrapper
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void HandlePawnEliminated(AFortPlayerPawnAthena* EliminatedPawn);

private:
	UFUNCTION()
	void HandlePossessedPawnChanged(APawn* OldPawn, APawn* NewPawn);

};

