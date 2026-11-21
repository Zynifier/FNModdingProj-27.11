// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAudioTypes.generated.h"

class UAudioComponent;
class UFortItemDefinition;

USTRUCT()
struct FEmoteAudioComponentData
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY()
	float FadeOutTime;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> EmoteItemDefinition;

	UPROPERTY()
	bool bShouldPersistOverMontages;

};

USTRUCT()
struct FFortAudioFloatParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAudioFloatParameter")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="Range")
	FVector2D InRange;

	UPROPERTY(EditDefaultsOnly, Category="Range")
	FVector2D OutRange;

	UPROPERTY(EditDefaultsOnly, Category="Interp")
	float InitialValue;

	UPROPERTY(EditDefaultsOnly, Category="Interp")
	float AttackInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Interp")
	float ReleaseInterpSpeed;

};

