// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortQueryTwoPointSolver.generated.h"

class UEnvQuery;
class UFortAISystem;
class UObject;

UENUM()
enum class ETwoPointSolverRotationA : uint8
{
	PointAToQuerier = 0,
	QuerierToPointA = 1,
	PointAToQuerierWithRandomOffset = 2,
	QuerierToPointAWithRandomOffset = 3,
	Custom = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTwoPointSolverFailed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTwoPointSolverFinished, FVector, PointA, FVector, PointB);

UCLASS(BlueprintType, Blueprintable)
class UFortQueryTwoPointSolver : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI|EQS")
	void AddNamedFloatParamA(FName ParamName, float Value);

	UFUNCTION(BlueprintCallable, Category="AI|EQS")
	void AddNamedFloatParamB(FName ParamName, float Value);

	UFUNCTION(BlueprintPure, Category="AI|EQS")
	FRotator GetRandomRotationOffset() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCustomRotationMode(UPARAM(DisplayName="PointA") const FVector& InPointA, const FVector Querier);

	UFUNCTION(BlueprintCallable, Category="AI|EQS")
	void SetCustomRotationA(const FRotator& Rotation);

	UFUNCTION(BlueprintCallable, Category="AI|EQS")
	void SkipToNextPointA();

	UFUNCTION(BlueprintCallable, Category="AI|EQS")
	void Start(UObject* Querier);

protected:
	UPROPERTY(EditAnywhere, Category="Query")
	TObjectPtr<UEnvQuery> QueryPointA;

	UPROPERTY(EditAnywhere, Category="Query")
	TObjectPtr<UEnvQuery> QueryPointB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Query")
	TArray<FEnvNamedValue> QueryParamsA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Query")
	TArray<FEnvNamedValue> QueryParamsB;

	UPROPERTY(BlueprintAssignable)
	FOnTwoPointSolverFinished OnFinished;

	UPROPERTY(BlueprintAssignable)
	FOnTwoPointSolverFailed OnFailed;

	UPROPERTY(EditAnywhere, Category="Query")
	ETwoPointSolverRotationA RotationMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Query")
	FRotator MinRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Query")
	FRotator MaxRotationOffset;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Query")
	uint8 bUseNegativeAngleOffsets : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Query")
	uint8 bUsePositiveAngleOffsets : 1;

	UPROPERTY(Transient)
	TObjectPtr<UFortAISystem> AISys;

	UPROPERTY(Transient)
	TObjectPtr<UObject> CachedQuerier;

};

