// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortExhibitActor.generated.h"

class UArrowComponent;
class UBillboardComponent;

UCLASS(Abstract)
class AFortExhibitActor : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Exhibit", meta=(MakeEditWidget))
	FTransform CameraOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Exhibit")
	float CameraFOV;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UArrowComponent> ArrowComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UArrowComponent> CameraArrowComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

};

