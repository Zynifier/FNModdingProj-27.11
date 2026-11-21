// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortCreativePhotoModeCamera.generated.h"

class UCameraComponent;

USTRUCT()
struct FPhotoModeData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, SaveGame, Category="PhotoModeData")
	FVector Location;

	UPROPERTY(VisibleInstanceOnly, SaveGame, Category="PhotoModeData")
	FRotator Rotation;

	UPROPERTY(VisibleInstanceOnly, SaveGame, Category="PhotoModeData")
	bool bIsValid;

};

UCLASS()
class AFortCreativePhotoModeCamera : public AActor, public ILevelSaveSpawnable
{
	GENERATED_BODY()

protected:
#if WITH_EDITOR
	UFUNCTION(Category="PhotoMode|Functions", meta=(CallInEditor="true"))
	void Editor_SaveNewTransform();
#endif

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Export, Category="PhotoMode|Camera", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> CameraComponent;
#endif

	UPROPERTY(EditInstanceOnly, SaveGame, Category="PhotoMode")
	FPhotoModeData PhotoData;

	UPROPERTY()
	FGuid SavedActorGuid;

};

