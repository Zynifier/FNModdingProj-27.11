// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "Stats/Stat.h"
#include "StatManager.generated.h"

class AController;
class UStat;

USTRUCT(BlueprintType)
struct FStatNamesToTrack : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats")
	FName StatName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats")
	EStatRecordingPeriod Period;

};

UCLASS()
class UBaseStatManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UStat>> Stats;

	UPROPERTY()
	FString StatPrefix;

	UPROPERTY()
	TWeakObjectPtr<AController> Controller;

};

UCLASS(MinimalAPI)
class UStatManager : public UBaseStatManager
{
	GENERATED_BODY()

};

