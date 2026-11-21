// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortAthenaLivingWorldPointProviderInterface.h"
#include "FortAthenaLivingWorldPointProviderUtils.h"
#include "FortAthenaLivingWorldStaticPointProvider.generated.h"

class AActor;
class AFortGameStateAthena;
class UBillboardComponent;
class UFortAthenaLivingWorldManager;
class UMaterialInterface;
class UMeshComponent;

UCLASS()
class LAGERRUNTIME_API AFortAthenaLivingWorldStaticPointProvider : public AActor, public IFortAthenaLivingWorldPointProviderInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorSpawned, AActor*, SpawnedActor);

public:
	UFUNCTION(BlueprintCallable)
	virtual void DisablePointProvider();

	UFUNCTION(BlueprintCallable)
	virtual void EnablePointProvider();

protected:
	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FFortAthenaLivingWorldPointProviderSpawnLimiter SpawnLimiter;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FGameplayTagContainer FiltersTags;

	UPROPERTY(EditAnywhere, Category="LivingWorld", meta=(MakeEditWidget="TRUE"))
	TArray<FTransform> SpawnPoints;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	bool bStartEnabled;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	bool bRandomizeStartPoint;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	bool bRandomizePointRotation;

	UPROPERTY(BlueprintAssignable)
	FOnActorSpawned OnActorSpawned;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TArray<FPointProviderTagDebugColor> DebugColors;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, EditFixedSize, Category="PreviewDisplay")
	TArray<TSubclassOf<AActor>> PreviewClasses;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="PreviewDisplay")
	TSoftObjectPtr<UMaterialInterface> EditorPreviewMeshOverrideMaterial;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UMeshComponent>> MeshComponents;
#endif

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedGameState;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaLivingWorldManager> CachedLivingWorldManager;

};

