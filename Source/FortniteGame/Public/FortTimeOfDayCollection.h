// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortTimeOfDayCollection.generated.h"

class AInfo;
class UFortTimeOfDayCollection;

USTRUCT()
struct FFortTimeOfDayTheme
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortTimeOfDayTheme")
	TArray<TObjectPtr<UFortTimeOfDayCollection>> TimeOfDayCollections;

	UPROPERTY(EditDefaultsOnly, Category="FortTimeOfDayTheme", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TArray<TSoftClassPtr<AInfo>> AdditionalTimeOfDayManagers;

	UPROPERTY(EditDefaultsOnly, Category="FortTimeOfDayTheme", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TArray<TSoftClassPtr<AInfo>> ProhibitedTimeOfDayManagers;

	UPROPERTY(Transient)
	TArray<TSoftClassPtr<AInfo>> ValidTimeOfDayManagers;

};

UCLASS()
class UFortTimeOfDayCollection : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="TimeOfDay", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TArray<TSoftClassPtr<AInfo>> TimeOfDayManagers;

};

