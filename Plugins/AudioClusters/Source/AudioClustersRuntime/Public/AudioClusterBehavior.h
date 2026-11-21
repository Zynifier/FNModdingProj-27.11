// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "AudioClusterBehavior.generated.h"

class AActor;

UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable)
class AUDIOCLUSTERSRUNTIME_API UAudioClusterBehavior : public UObject
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Actions")
	void OnActorAdded(AActor* Actor);

	UFUNCTION(BlueprintNativeEvent, Category="Actions")
	void OnActorRemoved(AActor* Actor);

	UFUNCTION(BlueprintNativeEvent, Category="Actions")
	void OnPositionUpdated(const FVector& Position);

	UFUNCTION(BlueprintNativeEvent, Category="Actions")
	void OnSizeUpdated(int32 Size);

	UFUNCTION(BlueprintNativeEvent, Category="Actions")
	void OnStart();

	UFUNCTION(BlueprintNativeEvent, Category="Actions")
	void OnStop();

};

