// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AudioWorldizationTraceDirectionPolicy.generated.h"

UENUM(BlueprintType)
enum class ETraceDirection : uint8
{
	N = 0,
	E = 1,
	S = 2,
	W = 3,
	Up = 4,
	None = 5,
};

USTRUCT(BlueprintType)
struct AUDIOWORLDIZATION_API FAudioSphereTraceResult
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AudioSphereTraceResult")
	bool bBlocking;

	UPROPERTY(BlueprintReadOnly, Category="AudioSphereTraceResult")
	float Distance;

};

UCLASS(BlueprintType)
class AUDIOWORLDIZATION_API UAudioWorldizationTraceDirectionPolicyBase : public UObject
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class AUDIOWORLDIZATION_API UAudioWorldizationTraceDirectionPolicyDefault : public UAudioWorldizationTraceDirectionPolicyBase
{
	GENERATED_BODY()

};

