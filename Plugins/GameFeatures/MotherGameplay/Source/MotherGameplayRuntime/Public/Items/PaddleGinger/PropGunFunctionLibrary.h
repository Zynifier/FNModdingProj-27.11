// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "MotherGameplayTypes.h"
#include "PropGunFunctionLibrary.generated.h"

class AActor;
class AFortPawn;
class USceneComponent;
class USkeletalMeshComponent;

UCLASS()
class UPropGunFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	static void ClearPropActivatedEventState(AActor* ContextActor);

	UFUNCTION(BlueprintCallable)
	static void ClearPropIndexEventState(AActor* ContextActor);

	UFUNCTION(BlueprintCallable)
	static void UpdatePropActivatedEventState(AActor* ContextActor, const FPaddleGingerPropActivatedData& Payload);

	UFUNCTION(BlueprintCallable)
	static void UpdatePropIndexEventState(AActor* ContextActor, const FPaddleGingerPropData& Payload);

	UFUNCTION(BlueprintCallable)
	static void UpdatePropPreviewPosition(USceneComponent* PropPreviewComponent, const float DeltaTime, const AFortPawn* AttachPawn, const FName AttachSocket, const USkeletalMeshComponent* WeaponMesh, const FVector& DesiredRelativeTransform, const float MinimumZOffset, const FRotator& RelativeRotation, const FVector& CachedScale, const float InterpSpeed);

};

