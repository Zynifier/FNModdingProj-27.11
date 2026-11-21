// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Rotation.generated.h"

USTRUCT()
struct FVerseRotation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Transform")
	FQuat Quaternion;

};

