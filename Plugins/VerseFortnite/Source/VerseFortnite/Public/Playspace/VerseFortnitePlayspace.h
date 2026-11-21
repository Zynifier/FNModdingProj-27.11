// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/NoExportTypes.h"
#include "VerseFortniteActorWrapper.h"
#include "VerseFortnitePlayspace.generated.h"

class AFortMinigame;
class UVerseFortnitePlayspaceExtensionBase;

UCLASS()
class VERSEFORTNITE_API UVerseFortnitePlayspace : public UVerseFortniteActorWrapper
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnMinigamePlayerAdded(FUniqueNetIdRepl UniqueNetId, bool bIsLocalPlayer);

	UFUNCTION()
	void OnMinigameSetup(AFortMinigame* Minigame);

	UPROPERTY(Transient)
	TArray<UVerseFortnitePlayspaceExtensionBase*> Extensions;

};

UCLASS(Abstract)
class VERSEFORTNITE_API UVerseFortnitePlayspaceExtensionBase : public UObject
{
	GENERATED_BODY()

};

