// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "CosmeticsEventRegistrar.h"
#include "CosmeticsEventTypes.h"
#include "Customization/BoneSetVisibilityInterface.h"
#include "Customization/CustomCharacterPartOwnerInterface.h"
#include "Customization/CustomizationItemInterface.h"
#include "FortCustomPartTypeEnum.h"
#include "FortGender.h"
#include "FortPlayerMannequin.generated.h"

class ACustomCharacterPartModifier;
class AFortPlayerPawn;
class AFortPlayerPet;
class UAthenaBackpackItemDefinition;
class UAthenaCharacterItemDefinition;
class UAthenaCosmeticItemDefinition;
class UAudioComponent;
class UCustomCharacterPart;
class UCustomColorComponent;
class UCustomColorSwatch;
class UFortCustomizationAssetLoader;
class UFortHeroType;
class UMaterialInstanceDynamic;
class USkeletalMesh;
class USkeletalMeshComponent;

UENUM()
enum class EFortPlayerMannequinLoadingMode : uint8
{
	/** All assets (character parts, variant assets, etc.) are loaded asynchronously */
	Asynchronous = 0,
	/** All assets are loaded synchronously. Only works in editor builds */
	Synchronous = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortPlayerMannequinMaterialDelegate, const TArray<UMaterialInstanceDynamic*>&, Materials);

USTRUCT(BlueprintType)
struct FMorphValuePair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MorphTargets")
	FName MorphName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MorphTargets", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0.0"))
	float MorphValue;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Materials"))
class AFortPlayerMannequin : public ASkeletalMeshActor, public ICustomCharacterPartOwnerInterface, public ICustomizationItemInterface, public IBoneSetVisibilityInterface, public ICosmeticsEventRegistrar
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Cosmetics")
	FORTNITEGAME_API void ClearExistingCosmeticPetInstance();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Cosmetics")
	FORTNITEGAME_API AFortPlayerPet* CreateCosmeticPetInstance(AFortPlayerPawn* InPawn);

	UFUNCTION(BlueprintCallable, Category="Customization", meta=(DisplayName="CyclePart"))
	FORTNITEGAME_API bool CyclePartBP(EFortCustomPartType::Type Part, bool bNextPart);

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API FGameplayTagContainer GatherMetaTags(const UAthenaCosmeticItemDefinition* CosmeticItem) const;

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API void GetAllPartSkeletalMeshComponents(TArray<USkeletalMeshComponent*>& SkeletalMeshComponents);

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API const UAthenaCharacterItemDefinition* GetAthenaCharacterItemDefinition() const;

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API TArray<UCustomCharacterPart*> GetCustomCharacterParts();

	UFUNCTION(BlueprintPure, Category="Emote")
	FORTNITEGAME_API UAudioComponent* GetEmoteAudioComponent(const FName InSoundId = NAME_None) const;

	UFUNCTION(BlueprintPure, Category="Customization")
	FORTNITEGAME_API EFortCustomGender::Type GetGender() const;

	UFUNCTION(BlueprintPure, Category="Customization")
	FORTNITEGAME_API USkeletalMeshComponent* GetPartSkeletalMeshComponent(EFortCustomPartType::Type Part) const;

	UFUNCTION(BlueprintPure, Category="Customization")
	FORTNITEGAME_API USkeletalMeshComponent* GetWeaponSkeletalMeshComponent() const;

	UFUNCTION(BlueprintImplementableEvent, meta=(CallInEditor="true"))
	FORTNITEGAME_API void HandleReInitializeComplete();

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Register On Cosmetic Application Completed"))
	FORTNITEGAME_API FCosmeticsEventHandle RegisterOnCosmeticApplicationCompleted_BP(const FCosmeticsEventTargetDynamicDelegate& Delegate, int32 Flags = 0);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API bool RemovePart(EFortCustomPartType::Type Part);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API void ResetAthenaCharacterDefAndVariants(UAthenaCharacterItemDefinition* NewAthenaCharacter, const TArray<FMcpVariantChannelInfo>& InOverrideVariants);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetAllowEmoteAudioComponents(const bool InAllowEmoteAudioComponents);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API void SetAthenaBackpackAndCharacterDefAndVariants(UAthenaBackpackItemDefinition* NewAthenaBackpack, const TArray<FMcpVariantChannelInfo>& InBackpackOverrideVariants, UAthenaCharacterItemDefinition* NewAthenaCharacter, const TArray<FMcpVariantChannelInfo>& InCharacterOverrideVariants);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API void SetAthenaBackpackDefAndVariants(UAthenaBackpackItemDefinition* NewAthenaBackpack, const TArray<FMcpVariantChannelInfo>& InOverrideVariants);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API void SetAthenaCharacterDefAndVariants(UAthenaCharacterItemDefinition* NewAthenaCharacter, const TArray<FMcpVariantChannelInfo>& InOverrideVariants);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API void SetHeroType(UFortHeroType* NewHeroType);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API void SetMannequinLightingChannels(bool bChannel0, bool bChannel1, bool bChannel2);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API bool SetPart(EFortCustomPartType::Type Part, UCustomCharacterPart* PartAsset);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API void SetSkeletalMesh(USkeletalMesh* SkeletalMesh);

	UFUNCTION(BlueprintCallable, Category="Customization")
	FORTNITEGAME_API bool SetWeaponSkeletalMesh(USkeletalMesh* SkeletalMesh);

	UFUNCTION(BlueprintCallable, Category="Customization", meta=(DisplayName="ToggleGender"))
	FORTNITEGAME_API void ToggleGenderBP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CharacterParts")
	TObjectPtr<UAthenaBackpackItemDefinition> AthenaBackBling;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="CharacterParts")
	bool bSpawnEditorPartModifiers;
#endif

	UPROPERTY(BlueprintAssignable)
	FFortPlayerMannequinMaterialDelegate OnMaterialsUpdated;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="MannequinNotifications")
	FORTNITEGAME_API void OnPartChanged(const UCustomCharacterPart* OldPart, const UCustomCharacterPart* NewPart, EFortCustomPartType::Type PartType);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="MannequinNotifications")
	FORTNITEGAME_API void OnVariantChanged(FGameplayTag VariantChannel, FGameplayTag OldVariantTag, FGameplayTag NewVariantTag);

	UFUNCTION()
	FORTNITEGAME_API virtual void UpdateMorphTargets();

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="CharacterParts")
	TObjectPtr<UFortHeroType> FortHeroType;
#endif

	UPROPERTY(Transient)
	TObjectPtr<UFortHeroType> CurrentFortHeroType;

	UPROPERTY(EditAnywhere, Category="CharacterParts")
	TObjectPtr<UAthenaCharacterItemDefinition> AthenaCharacter;

	UPROPERTY()
	TObjectPtr<UCustomCharacterPart> CharacterParts[8];

	UPROPERTY(EditAnywhere, Category="Lighting")
	FLightingChannels MannequinLightingChannels;

	UPROPERTY(EditAnywhere, Category="Rendering")
	float MannequinBoundsScale;

	UPROPERTY(EditAnywhere, Category="Rendering")
	bool bIsMannequinVisible;

	UPROPERTY(EditAnywhere, Category="Lighting")
	bool bMannequinCastsHiddenShadow;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UCustomCharacterPart>> LastRequestedParts;

	UPROPERTY(EditAnywhere, Category="CharacterParts", meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomCharacterPart> CharacterPartList[7];

	UPROPERTY(EditAnywhere, Category="CharacterParts")
	TArray<FMcpVariantChannelInfo> OverrideVariants;

	UPROPERTY()
	TObjectPtr<UCustomColorSwatch> CharacterPartColorSwatches[8];

	UPROPERTY(EditAnywhere, Category="ColorSwatches", meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType", DisplayName="Clothing and Accessory Color Swatches"))
	TObjectPtr<UCustomColorSwatch> ColorSwatchesForCharacterParts[7];

	UPROPERTY(Transient, Export, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType", EditInline="true"))
	TObjectPtr<UCustomColorComponent> AccessoryColorSwatchHandler[7];

	UPROPERTY(EditAnywhere, Category="ColorSwatches", meta=(ArraySizeEnum="/Script/FortniteGame.ECharacterColorSwatchType", DisplayName="Character Color Swatches"))
	TObjectPtr<UCustomColorSwatch> ColorSwatches[2];

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Instanced, Category="ColorSwatchEditing", meta=(ArraySizeEnum="/Script/FortniteGame.ECharacterColorSwatchType"))
	TObjectPtr<UCustomColorSwatch> EditColorSwatches[2];
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.ECharacterColorSwatchType"))
	TObjectPtr<UCustomColorSwatch> BackupColorSwatches[2];
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Instanced, Category="ColorSwatchEditing", meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomColorSwatch> EditPartColorSwatches[7];
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomColorSwatch> BackupPartColorSwatches[7];
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCustomPartType"))
	TObjectPtr<UCustomCharacterPart> BackupCharacterParts[7];
#endif

	UPROPERTY(EditAnywhere, Category="Weapon")
	TObjectPtr<USkeletalMesh> WeaponSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	FName WeaponAttachSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MorphTargets")
	TArray<FMorphValuePair> MorphTargets;

	UPROPERTY(Transient)
	bool bInitialized;

	UPROPERTY(EditAnywhere, Category="Optimizations")
	bool bLimitTick;

	UPROPERTY(EditAnywhere, Category="Optimizations")
	bool bAutoRegisterWithBudgetAllocator;

	UPROPERTY()
	TObjectPtr<ACustomCharacterPartModifier> PartModifiers[8];

private:
	UFUNCTION()
	FORTNITEGAME_API void ChoosePartsForHeroType(UFortHeroType* HeroType, const TArray<FMcpVariantChannelInfo> InOverrideVariants, const bool bClearOldParts);

	UPROPERTY(Transient)
	TObjectPtr<UFortCustomizationAssetLoader> CustomizationAssetLoader;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerMannequin")
	EFortPlayerMannequinLoadingMode LoadingMode;

};

