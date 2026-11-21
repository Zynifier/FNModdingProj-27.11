// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "ScalableFloat.h"
#include "FortCollisionResponseSwapperComponent.generated.h"

class AActor;
class AFortPawn;
class UPrimitiveComponent;

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortCollisionResponseSwapperComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void RegisterCallbacksForOverlap(UPrimitiveComponent* InCollisionPrimitiveComponent, UPrimitiveComponent* InOverlapPrimitiveComponent);

	UFUNCTION()
	void RestoreCollisionResponses();

	UFUNCTION(BlueprintCallable)
	void UnregisterCallbacksForOverlap();

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> CollisionPrimitiveComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> OverlapPrimitiveComponent;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPawn>> PawnsListenedTo;

	UPROPERTY(EditAnywhere, Category="FortCollisionResponseSwapperComponent", meta=(AllowPrivateAccess="true"))
	FScalableFloat VisibilityModifiedTime;

	UPROPERTY(EditAnywhere, Category="FortCollisionResponseSwapperComponent", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<ECollisionResponse> NewCollisionResponse;

};

