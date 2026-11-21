// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "SpecialEventHelpers.generated.h"

class AActor;
class AController;
class AFortAthenaMutator_SpecialRelevancy;
class AFortPlayerController;
class UObject;

UCLASS(MinimalAPI)
class USpecialEventHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static void GetActorsInBox(TArray<AActor*>& OutActors, const UObject* WorldContextObject, const TArray<TSubclassOf<AActor>>& ActorClasses, const FBox& SearchBox, const bool bTestActorBoundingBox, const bool bIncludeNonCollidingComponents, const bool bIncludeChildActorComponents, const bool bLog = false, const float DebugDrawLifeTime = 0.000000f);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, meta=(WorldContext="WorldContextObject"))
	static AFortAthenaMutator_SpecialRelevancy* GetSpecialRelevancyMutator(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure)
	static bool HasSeenEditIntro(AController* Player);

	UFUNCTION(BlueprintPure)
	static bool HasSeenForcedIntro(AController* Player);

	UFUNCTION(BlueprintCallable)
	static void MarkAccountAsHavingSeenEditIntro_LocalOnly(AFortPlayerController* Controller);

	UFUNCTION(BlueprintCallable)
	static void MarkAccountAsHavingSeenForcedIntro(AFortPlayerController* Controller, bool bLocalOnly = false);

};

