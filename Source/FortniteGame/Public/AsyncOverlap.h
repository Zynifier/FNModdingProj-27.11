// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "AsyncOverlap.generated.h"

class AActor;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnProcessComplete, bool, WasCancelled);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FProcessHitActor, AActor*, HitActor);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FShouldCancelOverlapProcess, bool&, ShouldCancel);

UCLASS()
class UAsyncOverlapQueue : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ActorsToIgnore", WorldContext="ContextActor"))
	static void AsyncSphereOverlapActors(AActor* ContextActor, const FVector& Location, const float Radius, const TArray<AActor*>& ActorsToIgnore, FShouldCancelOverlapProcess ShouldCancelProcess, FProcessHitActor ProcessHitActorFunction, FOnProcessComplete CompletionFunction, ECollisionChannel TraceChannel = ECC_Visibility);

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ActorsToIgnore,ObjectTypes", WorldContext="ContextActor"))
	void ThrottledAsyncSphereOverlapActors(AActor* ContextActor, const FVector& Location, const float Radius, const bool bCheckLineOfSight, const TArray<AActor*>& ActorsToIgnore, FShouldCancelOverlapProcess ShouldCancelProcess, FProcessHitActor ProcessHitActorFunction, FOnProcessComplete CompletionFunction, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, ECollisionChannel TraceChannel = ECC_Visibility);

};

