// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Track/FortTrack.h"
#include "FortTrack_CustomSpline.generated.h"

class USplineComponent;

UCLASS(NotBlueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=FortTrackActorClassData)
class AFortTrack_CustomSpline : public AFortTrack
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Export, Category="Track", meta=(EditInline="true"))
	TObjectPtr<USplineComponent> CustomSplineComp;

};

