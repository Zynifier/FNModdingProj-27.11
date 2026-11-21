// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreativeAttenuationVizComponent.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FCreativeAttenuationVizData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="CreativeAttenuation", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> MinSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="CreativeAttenuation", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> MaxSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAttenuation")
	float MinDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAttenuation")
	float FalloffDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAttenuation")
	bool bIsVisible;

};

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UCreativeAttenuationVizComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CreativeAttenuation")
	void SetProperties(const FCreativeAttenuationVizData& Data);

};

