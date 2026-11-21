// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "WeakPoints/FortWeakPoint.h"
#include "FortWeakPointsCoordinatorComponent.generated.h"

class AActor;
class AController;
class AFortWeakPoint;
class UGameplayEffect;
class UPrimitiveComponent;
enum class EFortWeakPointState : uint8;

USTRUCT()
struct FFortWeakPointTypeData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortWeakPointTypeData")
	FGameplayTag WeakPointsTag;

	UPROPERTY(EditAnywhere, Category="FortWeakPointTypeData")
	FScalableFloat StartActive;

	UPROPERTY(EditAnywhere, Category="FortWeakPointTypeData")
	FScalableFloat PassDamageToOwner;

	UPROPERTY(EditAnywhere, Category="FortWeakPointTypeData")
	FScalableFloat ResetHealthOnActivation;

	UPROPERTY(EditAnywhere, Category="FortWeakPointTypeData")
	FScalableFloat AllowWeakPointDestruction;

	UPROPERTY(EditAnywhere, Category="FortWeakPointTypeData")
	FScalableFloat DestroyedWeakPointAutoRegenerationTime;

	UPROPERTY(EditAnywhere, Category="FortWeakPointTypeData")
	TSubclassOf<UGameplayEffect> PassthroughDamageGEClass;

	UPROPERTY(EditAnywhere, Category="FortWeakPointTypeData")
	FGameplayTag SetByCallerDamageTag;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortWeakPoint>> WeakPointActors;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeakPointsCoordinatorComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortWeakPointsCoordinatorComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ActivateAllWeakPointsByTag(const FGameplayTag& WeakPointsTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void DeactivateAllWeakPointsByTag(const FGameplayTag& WeakPointsTag);

protected:
	UFUNCTION()
	void OnRep_WeakPoints();

	UFUNCTION()
	void OnWeakPointDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnWeakPointStateChanged(AFortWeakPoint* WeakPoint, EFortWeakPointState NewState);

	UPROPERTY(BlueprintAssignable)
	FFortOnWeakPointStateChanged OnWeakPointStateChangedDelegate;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_WeakPoints, Category="FortWeakPointsCoordinatorComponent")
	TArray<FFortWeakPointTypeData> WeakPointTypes;

};

