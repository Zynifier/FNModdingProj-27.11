// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortWindImpulse.generated.h"

USTRUCT(BlueprintType)
struct FFortWindImpulseHandle
{
	GENERATED_BODY()

private:
	UPROPERTY(meta=(IgnoreForMemberInitializationTest))
	int32 UID;

};

USTRUCT(BlueprintType)
struct FFortWindImpulseCylinderRadial
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Wind")
	FVector Location;

	UPROPERTY()
	float InnerRadius;

	UPROPERTY()
	float OuterRadius;

	UPROPERTY()
	float Magnitude;

	UPROPERTY()
	FBox WorldBounds;

	UPROPERTY()
	bool bIsChanging;

	UPROPERTY()
	bool bIsChangePending;

private:
	UPROPERTY(Transient, meta=(IgnoreForMemberInitializationTest))
	FFortWindImpulseHandle Handle;

};

USTRUCT(BlueprintType)
struct FFortWindImpulseCylinder : public FFortWindImpulseCylinderRadial
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Wind")
	FVector WindDirection;

};

USTRUCT(BlueprintType)
struct FFortWindImpulseCylinderDelta
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FVector DeltaCenter;

	UPROPERTY(Transient)
	bool bInitialized;

	UPROPERTY(Transient)
	bool bRippleOutward;

	UPROPERTY(Transient)
	float SectionWidth;

	UPROPERTY(Transient)
	float InnerSectionRadius;

	UPROPERTY(Transient)
	float OuterSectionRadius;

	UPROPERTY(Transient)
	float MaximumRadius;

	UPROPERTY(Transient)
	float DesiredOverallBlendTime;

	UPROPERTY(Transient)
	float SectionBlendTime;

	UPROPERTY(Transient)
	float SectionCurrentBlendTime;

	UPROPERTY(Transient)
	float PreviousMagnitude;

	UPROPERTY(Transient)
	float SectionCurrentMagnitude;

	UPROPERTY(Transient)
	float DesiredMagnitude;

	UPROPERTY(Transient)
	FBox OuterWorldBounds;

	UPROPERTY(Transient)
	FBox InnerWorldBounds;

	UPROPERTY(Transient)
	FBox WindImpulseBounds;

	UPROPERTY(Transient)
	FFortWindImpulseHandle WindImpulseHandleToModify;

};

USTRUCT(BlueprintType)
struct FFortWindImpulseRadius
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Wind")
	FVector Location;

	UPROPERTY(EditAnywhere, Category="Wind")
	float Radius;

	UPROPERTY()
	float CurrentRadius;

	UPROPERTY()
	float PreviousRadius;

	UPROPERTY(EditAnywhere, Category="Wind")
	float Magnitude;

	UPROPERTY()
	float CurrentMagnitude;

	UPROPERTY()
	float PreviousMagnitude;

	UPROPERTY(EditAnywhere, Category="Wind")
	float BlendTime;

	UPROPERTY()
	float CurrentBlendTime;

	UPROPERTY()
	FBox WorldBounds;

private:
	UPROPERTY(Transient, meta=(IgnoreForMemberInitializationTest))
	FFortWindImpulseHandle Handle;

};

