// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/EditorOnlyBuildingInstanceMaterialParameters.h"
#include "FortStaticMeshActor.h"
#include "BuildingStaticGeo.generated.h"

class UBuildingTextureData;
class UMaterialInterface;
class UNaniteDisplacedMesh;
class URuntimeVirtualTexture;
class UStaticMeshComponent;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), meta=(DisplayName="Building Static Mesh (Static Geo)"))
class ABuildingStaticGeo : public AFortStaticMeshActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	UMaterialInterface* GetOverrideMeshMaterial(UStaticMeshComponent* MeshComp, int32 MatIdx) const;

	UPROPERTY(EditAnywhere, Category="BuildingStaticGeo", meta=(ArraySizeEnum="/Script/FortniteGame.EFortTextureDataSlot"))
	TObjectPtr<UBuildingTextureData> TextureData[4];

	UPROPERTY(EditAnywhere, Category="BuildingStaticGeo")
	TObjectPtr<URuntimeVirtualTexture> RVTHeightOverride;

	UPROPERTY(EditAnywhere, Category="BuildingStaticGeo")
	TObjectPtr<URuntimeVirtualTexture> RVTColorOverride;

	UPROPERTY(EditInstanceOnly, Category="BuildingStaticGeo")
	FEditorOnlyBuildingInstanceMaterialParameters EditorOnlyInstanceMaterialParameters;

	UPROPERTY(VisibleAnywhere, Category="BuildingStaticGeo")
	TObjectPtr<UNaniteDisplacedMesh> DisplacedMesh;

};

