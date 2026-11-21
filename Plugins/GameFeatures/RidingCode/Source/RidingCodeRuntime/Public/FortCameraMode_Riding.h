// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortCameraMode_Riding.generated.h"

UCLASS(BlueprintType, Blueprintable)
class RIDINGCODERUNTIME_API UFortCameraMode_Riding : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Riding")
	FVector OriginOffset;

};

