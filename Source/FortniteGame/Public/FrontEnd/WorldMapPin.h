// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldMapPin.generated.h"

class USceneComponent;

UCLASS(BlueprintType)
class AWorldMapPin : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTheaterIdSet();

	UFUNCTION(BlueprintCallable, Category="WorldMapPin")
	void SetTheaterId(const FString& NewId);

protected:
	UPROPERTY(BlueprintReadOnly, Category="WorldMapPin")
	FString TheaterId;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="WorldMapPin", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USceneComponent> SceneComponent;

};

