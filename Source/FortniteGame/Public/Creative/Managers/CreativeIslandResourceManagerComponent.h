// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "Online/FortRuntimeOptions.h"
#include "CreativeIslandResourceManagerComponent.generated.h"

UCLASS()
class UCreativeIslandResourceManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void FreeResource(const FName Tag, const FVector& WorldLocation);

	UFUNCTION(BlueprintCallable)
	bool RequestResource(const FName Tag, const FVector& WorldLocation);

private:
	UPROPERTY()
	TArray<FCreativeIslandResource> Resources;

};

