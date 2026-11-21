// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontEnd/FortItemPreviewActor.h"
#include "FortItemPreviewSingleAngleActor.generated.h"

class UCameraComponent;

UCLASS()
class AFortItemPreviewSingleAngleActor : public AFortItemPreviewActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewSingleAngleActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedOutCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewSingleAngleActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UCameraComponent> ZoomedInCameraComponent;

};

