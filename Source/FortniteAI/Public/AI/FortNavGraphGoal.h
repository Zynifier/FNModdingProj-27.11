// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortInitializationInterface.h"
#include "FortNavGraphGoal.generated.h"

class UBillboardComponent;

UCLASS()
class AFortNavGraphGoal : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComp;
#endif

	UPROPERTY(EditAnywhere, Category="AI")
	float GraphRadius;

};

