// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortUIDirectorSubsystemBase.h"
#include "FortUIDirector.generated.h"

class UFortUIManager;

USTRUCT()
struct FLoadedUIManagerEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<UFortUIManager> UIManagerClass;

};

USTRUCT()
struct FRegisteredUIManagerEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftClassPtr<UFortUIManager> UIManagerClass;

};

UCLASS(Config=Game)
class UFortUIDirector : public UFortUIDirectorSubsystemBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FLoadedUIManagerEntry> LoadedManagerClassesBySubgame;

	UPROPERTY(Transient)
	TObjectPtr<UFortUIManager> CurrentManager;

};

