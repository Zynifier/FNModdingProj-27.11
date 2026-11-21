// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "FortEditorPreviewInterface.h"
#include "CreativeEditOnlyMeshComponent.generated.h"

class AFortMinigame;
class UMaterialInterface;
class UStaticMesh;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoadComplete);

UCLASS(MinimalAPI, BlueprintType, HideCategories=("StaticMesh", "ComponentTick", "Physics", "VirtualTextures", "ComponentReplication", "Cooking", "AssetUserData", "Object", "Activation", "Components|Activation", "Trigger"), meta=(BlueprintSpawnableComponent))
class UCreativeEditOnlyMeshComponent : public UStaticMeshComponent, public IEditorPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const TSoftObjectPtr<UStaticMesh>& GetEditMesh() const;

	UFUNCTION(BlueprintPure)
	const TArray<TSoftObjectPtr<UMaterialInterface>>& GetEditOverrideMaterials() const;

	UFUNCTION(BlueprintPure)
	const TArray<TSoftObjectPtr<UMaterialInterface>>& GetPreviewOverrideMaterials() const;

	UFUNCTION(BlueprintPure)
	const TSoftObjectPtr<UStaticMesh>& GetPreviewOverrideMesh() const;

	UFUNCTION(BlueprintPure)
	bool IsLoadingAssets() const;

	UFUNCTION(BlueprintCallable)
	void ReloadMeshAndMaterials();

	UFUNCTION(BlueprintCallable)
	void SetAndApplyCachedMeshAndMaterials(UStaticMesh* InCachedMesh, TArray<UMaterialInterface*> InCachedMaterials);

	UFUNCTION(BlueprintCallable)
	void SetEditMeshAndMaterials(const TSoftObjectPtr<UStaticMesh>& InEditMesh, const TArray<TSoftObjectPtr<UMaterialInterface>>& InEditMaterials, bool bClobberBuiltInRefs = false);

	UFUNCTION(BlueprintCallable)
	void SetPreviewMeshAndMaterials(const TSoftObjectPtr<UStaticMesh>& InPreviewMesh, const TArray<TSoftObjectPtr<UMaterialInterface>>& InPreviewMaterials, bool bClobberBuiltInRefs = false);

	UFUNCTION(BlueprintPure)
	bool ShouldShowInPreview() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Setup For Editor Preview"))
	void K2_SetupForEditorPreview();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Update Editor Preview"))
	void K2_UpdateEditorPreview(bool bHasMoved);

	UPROPERTY(EditDefaultsOnly, Category="CreativeEditOnlyMeshComponent")
	bool bLoadOnServer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CreativeEditOnlyMeshComponent")
	bool bUseStaticRotation;

	UPROPERTY(EditDefaultsOnly, Category="CreativeEditOnlyMeshComponent")
	bool bEditMeshCanBeNull;

	UPROPERTY(EditDefaultsOnly, Category="CreativeEditOnlyMeshComponent")
	TSoftObjectPtr<UStaticMesh> EditMesh;

	UPROPERTY(Transient)
	TSoftObjectPtr<UStaticMesh> RuntimeEditMesh;

	UPROPERTY(EditDefaultsOnly, Category="CreativeEditOnlyMeshComponent")
	TArray<TSoftObjectPtr<UMaterialInterface>> EditOverrideMaterials;

	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<UMaterialInterface>> RuntimeEditOverrideMaterials;

	UPROPERTY(EditDefaultsOnly, Category="CreativeEditOnlyMeshComponent")
	bool bShowInPreview;

	UPROPERTY(EditDefaultsOnly, Category="CreativeEditOnlyMeshComponent", meta=(EditCondition="bShowInPreview"))
	TSoftObjectPtr<UStaticMesh> PreviewOverrideMesh;

	UPROPERTY(Transient)
	TSoftObjectPtr<UStaticMesh> RuntimePreviewOverrideMesh;

	UPROPERTY(EditDefaultsOnly, Category="CreativeEditOnlyMeshComponent", meta=(EditCondition="bShowInPreview"))
	TArray<TSoftObjectPtr<UMaterialInterface>> PreviewOverrideMaterials;

	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<UMaterialInterface>> RuntimePreviewOverrideMaterials;

	UPROPERTY(BlueprintAssignable)
	FOnLoadComplete OnMeshAndMaterialsLoaded;

private:
	UFUNCTION(BlueprintPure)
	bool IsEditorPreview() const;

	UFUNCTION()
	void OnMinigamePlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode);

	UPROPERTY(Transient)
	TObjectPtr<UStaticMesh> CachedMesh;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInterface>> CachedOverrideMaterials;

};

