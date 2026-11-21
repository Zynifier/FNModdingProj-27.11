// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "FortPhysicsConstantForceComponent.generated.h"

class AActor;

USTRUCT()
struct FConstantForceAsyncInPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FConstantForceAsyncOutContinuous
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FForceComponentMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ForceComponentMessage")
	TWeakObjectPtr<AActor> NewOwningActor;

};

USTRUCT()
struct FPhysicsConstantForceData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantize Force;

	UPROPERTY()
	FVector_NetQuantize Location;

	UPROPERTY()
	uint8 bAtLocation : 1;

	UPROPERTY()
	uint8 bLocationIsRelative : 1;

	UPROPERTY()
	uint8 bForceIsRelative : 1;

	UPROPERTY()
	uint8 bVelocityChange : 1;

	UPROPERTY()
	uint8 bUseLegacyDeltaSecondsBehavior : 1;

	UPROPERTY()
	uint8 bApplyDrag : 1;

	UPROPERTY()
	float DragCoeff;

	UPROPERTY()
	float DragAreaApproximation;

	UPROPERTY()
	uint8 bReduceForceOverDist;

	UPROPERTY()
	FVector_NetQuantize ForceReductionNormal;

	UPROPERTY()
	float StartValue;

	UPROPERTY()
	float EndValue;

	UPROPERTY()
	FName BoneName;

	UPROPERTY()
	AActor* ForceRoot;

	UPROPERTY()
	AActor* ForceOrigin;

};

USTRUCT(BlueprintType)
struct FPhysicsConstantForceHandle
{
	GENERATED_BODY()

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPhysicsConstantForceComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortPhysicsConstantForceComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void BeginConstantForce(FVector Force, bool bForceIsRelative, bool bAtLocation, FVector Location, bool bLocationIsRelative, bool bVelocityChange, FName BoneName, UPARAM(DisplayName="Handle") FPhysicsConstantForceHandle& OutHandle);

	UFUNCTION(BlueprintCallable)
	void BeginForce(FVector Force, bool bForceIsRelative, bool bAtLocation, FVector Location, bool bLocationIsRelative, bool bVelocityChange, bool bChangeForceOverDist, bool bApplyDrag, FName BoneName, FPhysicsConstantForceHandle& OutHandle, FVector ForceReductionNormal = FVector(0.000000, 0.000000, 1.000000), float Start = 0.000000f, float End = 1000.000000f, float DragCoeff = 0.100000f, float DragAreaApproximation = 100.000000f, AActor* RootActor = nullptr, AActor* Origin = nullptr);

	UFUNCTION(BlueprintCallable)
	void BeginZVariableForce(FVector Force, bool bForceIsRelative, bool bAtLocation, FVector Location, bool bLocationIsRelative, bool bVelocityChange, bool bApplyDrag, bool bReduceForceOverDistZ, FName BoneName, UPARAM(DisplayName="Handle") FPhysicsConstantForceHandle& OutHandle, float Start = 0.000000f, float End = 1000.000000f, float DragCoeff = 0.100000f, float DragAreaApproximation = 100.000000f);

	UFUNCTION(BlueprintCallable)
	void EndAllConstantForces();

	UFUNCTION(BlueprintCallable)
	void EndConstantForce(UPARAM(ref) FPhysicsConstantForceHandle& Handle);

	UFUNCTION(BlueprintCallable)
	void ModifyConstantForce(const FPhysicsConstantForceHandle& Handle, FVector Force, bool bForceIsRelative, bool bAtLocation, FVector Location, bool bLocationIsRelative, bool bVelocityChange, FName BoneName);

	UPROPERTY(BlueprintReadWrite, Replicated, Category="FortPhysicsConstantForceComponent")
	bool bActivateFortPhysicsObjectOnBeginConstantForce;

private:
	UPROPERTY(Transient, Replicated)
	TArray<FPhysicsConstantForceData> ForcesToApply;

	UPROPERTY(Config)
	bool bUseLegacyDeltaSecondsBehavior;

};

