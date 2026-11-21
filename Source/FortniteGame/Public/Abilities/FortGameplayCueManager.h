// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueManager.h"
#include "FortGameplayCueManager.generated.h"

class UObject;

UCLASS(Config=Game)
class UFortGameplayCueManager : public UGameplayCueManager
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FString> BROnlyGameplayCueNotifyPaths;

	UPROPERTY(Config)
	TArray<FName> AdditionalAlwaysLoadedCueTags;

	UPROPERTY(Transient)
	TSet<TSubclassOf<UObject>> PreloadedCues;

	UPROPERTY(Transient)
	TSet<TSubclassOf<UObject>> AlwaysLoadedCues;

	UPROPERTY(Config)
	bool bClientDelayLoadGameplayCues;

};

