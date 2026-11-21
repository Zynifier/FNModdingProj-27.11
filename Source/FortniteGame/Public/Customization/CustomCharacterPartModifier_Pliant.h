// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartModifier.h"
#include "CustomCharacterPartModifier_Pliant.generated.h"

class UCurveFloat;

UCLASS()
class ACustomCharacterPartModifier_PliantBody : public ACustomCharacterPartModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Bounds")
	FName UpperSocket;

	UPROPERTY(EditAnywhere, Category="Bounds")
	FName LowerSocket;

	UPROPERTY(EditAnywhere, Category="Bounds")
	FName LeftSocket;

	UPROPERTY(EditAnywhere, Category="Bounds")
	FName RightSocket;

	UPROPERTY(EditAnywhere, Category="Bounds")
	FName BackSocket;

	UPROPERTY(EditAnywhere, Category="Bounds")
	FName ForwardSocket;

	UPROPERTY(EditAnywhere, Category="Bounds")
	FName CenterReferenceSocket;

	UPROPERTY(EditAnywhere, Category="Bounds")
	FName RootReferenceSocket;

	UPROPERTY(EditAnywhere, Category="Primitive Data")
	int32 TypeDataIndex;

	UPROPERTY(EditAnywhere, Category="Primitive Data", meta=(ClampMax="3.0", ClampMin="0.0"))
	float TypeValue;

	UPROPERTY(EditAnywhere, Category="Primitive Data")
	int32 MinDataIndex;

	UPROPERTY(EditAnywhere, Category="Primitive Data")
	int32 MaxDataIndex;

	UPROPERTY(EditAnywhere, Category="Primitive Data")
	int32 ReferencePointDataIndex;

	UPROPERTY(EditAnywhere, Category="Crouch")
	TObjectPtr<UCurveFloat> CrouchCurve;

	UPROPERTY(EditAnywhere, Category="Crouch")
	FVector2D InputRange;

	UPROPERTY(EditAnywhere, Category="Crouch")
	FVector2D CrouchedOutputRange;

	UPROPERTY(EditAnywhere, Category="Crouch")
	FVector2D UncrouchedOutputRange;

};

