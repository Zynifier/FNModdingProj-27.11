// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortDataStore_AudioComponentParameters.generated.h"

USTRUCT(BlueprintType)
struct FFortBasicAudioParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortBasicAudioParam")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortBasicAudioParam")
	int32 Value;

};

USTRUCT()
struct FFortBasicAudioParamList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortBasicAudioParam> Params;

};

UCLASS()
class UFortDataStore_AudioComponentParameters : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FName, FFortBasicAudioParamList> NamedParameterGroupMap;

};

