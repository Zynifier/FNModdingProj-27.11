// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "FortWindResponder.generated.h"

class ABuildingSMActor;
class UCurveLinearColor;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USoundBase;

USTRUCT()
struct FFortMaterialParameterID
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 VariableIndex;

	UPROPERTY()
	FName VariableName;

};

USTRUCT()
struct FFortWindMaterialParameterPairID
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PairIndex;

	UPROPERTY()
	FFortMaterialParameterID SpeedParameter;

	UPROPERTY()
	FFortMaterialParameterID OffsetParameter;

};

USTRUCT()
struct FWindScalarMaterialInterpolationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName MaterialParameterName;

	UPROPERTY()
	int32 MaterialParameterIndex;

	UPROPERTY()
	float LerpFromValue;

	UPROPERTY()
	float LerpToValue;

};

USTRUCT()
struct FWindVectorMaterialInterpolationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName MaterialParameterName;

	UPROPERTY()
	int32 MaterialParameterIndex;

	UPROPERTY()
	FLinearColor LerpFromValue;

	UPROPERTY()
	FLinearColor LerpToValue;

};

USTRUCT()
struct FFortWindMaterialData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> MID;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> IntenseStateMID;

	UPROPERTY()
	int32 MaterialParameterPairIndices;

	UPROPERTY()
	int32 WindVectorParameterIndex;

	UPROPERTY()
	TArray<FWindScalarMaterialInterpolationData> ScalarInterpolationData;

	UPROPERTY()
	TArray<FWindVectorMaterialInterpolationData> VectorInterpolationData;

	UPROPERTY()
	TArray<FFortWindMaterialParameterPairID> ParametersToSet;

};

USTRUCT()
struct FFortWindResponderMaterialVariablePairData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float PreviousSpeed;

	UPROPERTY()
	float PreviousOffset;

	UPROPERTY()
	float MaterialsPreviousTime;

	UPROPERTY()
	float DeltaTimeModifiedByMaterialSpeed;

	UPROPERTY()
	int32 MaterialVariableIndex;

	UPROPERTY()
	FName SpeedVariableName;

	UPROPERTY()
	FName TimeOffsetVariableName;

};

USTRUCT()
struct FFortWindResponder
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<ABuildingSMActor> WindUpdatingBuildingSMActor;

	UPROPERTY(Transient)
	TObjectPtr<UCurveLinearColor> WindSpeedCurve;

	UPROPERTY(Transient)
	TObjectPtr<UCurveLinearColor> WindPannerSpeedCurve;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> WindAudio;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInterface>> MildWindMaterialInstances;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInterface>> IntenseWindMaterialInstances;

	UPROPERTY(Transient)
	TArray<FFortWindMaterialData> MaterialsData;

	UPROPERTY(Transient)
	int32 MaterialParameterPairIndices;

	UPROPERTY(Transient)
	TArray<FFortWindResponderMaterialVariablePairData> PairedVariablesData;

	UPROPERTY(Transient)
	float WindSpeed;

	UPROPERTY(Transient)
	bool bHasSetupAnimatingMaterials;

};

