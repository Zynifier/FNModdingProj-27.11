// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Types/SlateEnums.h"
#include "Athena/Markers/FortWorldMarkerTypeEnum.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_MarkLocation.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_MarkLocation : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_MarkLocation")
	EFortWorldMarkerType MarkerType;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_MarkLocation")
	FVector2D MobilePosition;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_MarkLocation")
	TEnumAsByte<EHorizontalAlignment> MobileHorizontalAlignment;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_MarkLocation")
	TEnumAsByte<EVerticalAlignment> MobileVerticalAlignment;

};

