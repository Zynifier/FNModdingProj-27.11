// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AthenaNavInvokerBox.generated.h"

class UBillboardComponent;
class UBoxComponent;
class UNavigationInvokerComponent;

UCLASS(MinimalAPI, HideCategories=("Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AAthenaNavInvokerBox : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Navigation")
	void SetInvokerEnabled(bool bEnable);

private:
	UPROPERTY(EditAnywhere, Category="Navigation", meta=(ClampMin="1", UIMin="1"))
	float GenerationRange;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UNavigationInvokerComponent> InvokerComp;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> BoxComponent;
#endif

};

