// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScalableFloat.h"
#include "FortWeightedActorClassList.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FFortWeightedActorTypeList
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortWeightedActorTypeList")
	TMap<TSubclassOf<AActor>, FScalableFloat> WeightedClassTypes;

};

UCLASS(meta=(ScriptName="WeightedActorClassListLibrary"))
class UWeightedActorClassListLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool IsListValid(const FFortWeightedActorTypeList& QueryList);

	UFUNCTION(BlueprintCallable)
	static TSubclassOf<AActor> SelectRandomActorTypeFromList(const FFortWeightedActorTypeList& QueryList);

	UFUNCTION(BlueprintCallable)
	static TSubclassOf<AActor> SelectRandomActorTypeFromListWithDebug(const FFortWeightedActorTypeList& QueryList, AActor* DebugContextActor);

};

