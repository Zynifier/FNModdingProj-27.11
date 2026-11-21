// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "FortAthenaLivingWorldWardComponent.generated.h"

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortAthenaLivingWorldWardComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWardRadius(float Radius);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Living World Ward")
	float DefaultRadius;

private:
	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnWorldFinishedInitialization(const FGameplayTagContainer& ContextTags);

};

